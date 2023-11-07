/**
 * @typedef Player
 * @prop {number} id
 * @prop {string} name
 * @prop {number} x
 * @prop {number} y
 * @prop {number} angle
 * @prop {boolean} alive
 * @prop {number} tank_id
 * @prop {number} tank_radius
 * @prop {number} range
 * @prop {number} health
 * @prop {number} max_health
 * @prop {number} score
 * @prop {Stats} stats
 */

/**
 * @typedef Position
 * @prop {number} x
 * @prop {number} y
 */

/**
 * @typedef Bullet
 * @prop {number} id
 * @prop {number} radius
 * @prop {Position} position
 * @prop {number} shooter_id
 */

/**
 * @typedef Entity
 * @prop {number} radius
 * @prop {Position} position
 */

/**
 * @typedef Stats
 * @prop {number} range
 * @prop {number} speed
 * @prop {number} bullet_speed
 * @prop {number} bullet_ttl
 * @prop {number} bullet_damage
 * @prop {number} health_max
 * @prop {number} health_regeneration
 * @prop {number} body_damage
 * @prop {number} reload_speed
 */

/**
 * @typedef Frame
 * @prop {Player[]} players
 * @prop {Bullet[]} bullets
 * @prop {Entity[]} entities
 * @prop {number} min_x
 * @prop {number} min_y
 * @prop {number} max_x
 * @prop {number} max_y
 * @prop {number} tick_number
 */

class Renderer {
    constructor() {
        this.app = new PIXI.Application({ background: '#111', resizeTo: document.body, antialias: true })
        document.body.appendChild(this.app.view)

        /** @type {Object.<number, _Container>}} */
        this.worldPlayers = {}
        /** @type {Frame} */
        this.currentFrame = null
        /** @type {Object.<number, _Graphics>}} */
        this.worldBullets = {}
        /** @type {_Graphics} */
        this.worldBorder = null
        /** @type {number} */
        this.frameSpeed = 10

        /** @type {_Container} */
        this.entityLayer = null

        /** @type {_Container} */
        this.world = new PIXI.Container()
        this.app.stage.addChild(this.world)
        this.app.ticker.add(() => TWEEDLE.Group.shared.update())
        this.app.ticker.add(() => this.recenter())
        // this.world.x = this.app.screen.width / 2
        // this.world.y = this.app.screen.height / 2
        // this.world.scale.x = 0.5
        // this.world.scale.y = 0.5

        const scoreboardContainer = new PIXI.Container()
        this.scoreboard = new Scoreboard(scoreboardContainer)
        scoreboardContainer.x = this.app.screen.width - this.scoreboard.width - 20
        scoreboardContainer.y = 10
        this.app.stage.addChild(scoreboardContainer)
        this.toBeDestroyed = []
        this.tweens = []
    }

    _destroyObjects() {
        for (const tw of this.tweens) {
            tw.end()
        }

        for (const obj of this.toBeDestroyed) {
            obj.destroy(true)
        }
        this.toBeDestroyed = []
        this.tweens = []
    }

    /**
     * @param {Frame} frame
     */
    render(frame) {
        this._destroyObjects()
        this.currentFrame = frame
        this.renderBorder(frame.min_x, frame.min_y, frame.max_x, frame.max_y)
        this.scoreboard.render(frame.players, this.frameSpeed)

        // Players
        for (const player of frame.players) {
            if (!player.alive) {
                if (player.id in this.worldPlayers) {
                    this.world.removeChild(this.worldPlayers[player.id])
                    this.toBeDestroyed.push(this.worldPlayers[player.id])
                    delete this.worldPlayers[player.id]
                }
                continue
            }

            this.renderPlayer(player)
        }

        // Bullets
        let currentBullets = new Set()
        for (const bullet of frame.bullets) {
            currentBullets.add(bullet.id)
            this.renderBullet(bullet)
        }

        for (const i of Object.keys(this.worldBullets)) {
            if (!currentBullets.has(parseInt(i))) {
                this.world.removeChild(this.worldBullets[i])
                this.toBeDestroyed.push(this.worldBullets[i])
                delete this.worldBullets[i]
            }
        }

        // Entities
        if (this.entityLayer) {
            this.world.removeChild(this.entityLayer)
            this.toBeDestroyed.push(this.entityLayer)
        }
        this.entityLayer = new PIXI.Container()
        this.world.addChildAt(this.entityLayer, 1)
        for (const entity of frame.entities) {
            this.renderEntity(entity)
        }
    }

    recenter() {
        if (this.currentFrame === null) {
            return
        }

        let minX, minY, maxX, maxY;
        maxX = maxY = -Infinity
        minX = minY = Infinity

        for (const player of this.currentFrame.players) {
            if (!player.alive) {
                continue
            }
            minX = Math.min(minX, player.x - player.range)
            maxX = Math.max(maxX, player.x + player.range)
            minY = Math.min(minY, -player.y - player.range)
            maxY = Math.max(maxY, -player.y + player.range)
        }

        const boxWidth = maxX - minX + 100
        const boxHeight = maxY - minY + 100

        const zoom = Math.min(this.app.screen.width / boxWidth, this.app.screen.height / boxHeight)
        const centerX = (maxX + minX) / 2
        const centerY = (maxY + minY) / 2
        this._tween(this.world, {
            x: this.app.screen.width / 2 - centerX * zoom,
            y: this.app.screen.height / 2 - centerY * zoom,
            scale: {
                x: zoom,
                y: zoom,
            }
        })
    }

    /**
     * @param {Player} player
     */
    playerGraphics(player) {
        const g = new PIXI.Graphics()
        const color = playerColor(player.id)

        g.beginFill(color, 0.1)
        g.drawCircle(0, 0, player.range)
        g.endFill();

        render_tank(g, color, player);

        return g
    }

    /**
     * @param {Player} player
     */
    playerHealthbar(player) {
        const g = new PIXI.Graphics()
        g.name = "healthbar"

        const h = (player.health / player.max_health)
        g.beginFill(h > 0.2 ? 0xffffff : 0xff0000)
        g.moveTo(-15, - player.tank_radius - 15)
        g.lineTo(-15+h*30, - player.tank_radius - 15)
        g.lineTo(-15+h*30, - player.tank_radius - 20)
        g.lineTo(-15, - player.tank_radius - 20)
        g.endFill()

        g.lineStyle(2, 0xffffff, 1)
        g.moveTo(-15, - player.tank_radius - 15)
        g.lineTo(15, - player.tank_radius - 15)
        g.lineTo(15, - player.tank_radius - 20)
        g.lineTo(-15, - player.tank_radius - 20)
        g.closePath()

        return g
    }

    /**
     * @param {Player} player
     */
    renderPlayer(player) {
        if (!(player.id in this.worldPlayers)) {
            const playerCont = new PIXI.Container()
            const tankCont = new PIXI.Container()
            tankCont.name = "tank"
            tankCont.rotation = -player.angle + Math.PI/2
            playerCont.addChild(tankCont)

            const nameText = new PIXI.Text(`${player.name}`, {
                fontSize: 50,
                fontWeight: "bold",
                fill: "#fff",
            })
            nameText.anchor.set(0.5, 0)
            nameText.name = "nameText"

            playerCont.addChild(nameText)

            playerCont.x = player.x
            playerCont.y = -player.y
            this.worldPlayers[player.id] = playerCont
            this.world.addChild(playerCont)
        }

        const wp = this.worldPlayers[player.id]
        for (const child of wp.getChildByName("tank").removeChildren()) {
            this.toBeDestroyed.push(child)
        }
        wp.getChildByName("tank").addChild(this.playerGraphics(player))
        const healthbar = wp.getChildByName("healthbar")
        if (healthbar != null) {
            wp.removeChild(healthbar)
            this.toBeDestroyed.push(healthbar)
        }
        wp.addChild(this.playerHealthbar(player))

        this._tween(wp, {
            x: player.x,
            y: -player.y,
        })
        this._tween(wp.getChildByName("tank"), {
            rotation: -player.angle + Math.PI/2
        })
    }

    /**
     * @param {Bullet} bullet
     */
    renderBullet(bullet) {
        if (!(bullet.id in this.worldBullets)) {
            const b = new PIXI.Graphics();
            b.beginFill(playerColor(bullet.shooter_id), 1);
            b.drawCircle(0, 0, bullet.radius);
            b.endFill();
            b.x = bullet.position.x
            b.y = -bullet.position.y
            this.worldBullets[bullet.id] = b
            this.world.addChildAt(b, 1)
        }

        const wb = this.worldBullets[bullet.id]
        this._tween(wb, {
            x: bullet.position.x,
            y: -bullet.position.y,
        })
    }

    /**
     * @param {number} x1
     * @param {number} y1
     * @param {number} x2
     * @param {number} y2
     */
    renderBorder(x1, y1, x2, y2) {
        if (this.worldBorder) {
            this.world.removeChild(this.worldBorder)
            this.toBeDestroyed.push(this.worldBorder)
        }

        const g = new PIXI.Graphics()
        g.lineStyle(1, 0xffffff, 0.8)
        g.beginFill(0xffffff, 0.1)
        g.moveTo(x1, -y1)
        g.lineTo(x1, -y2)
        g.lineTo(x2, -y2)
        g.lineTo(x2, -y1)
        g.closePath()
        this.worldBorder = g
        this.world.addChildAt(g, 0)
    }

    /** @type {Entity} entity */
    renderEntity(entity) {
        const b = new PIXI.Graphics();
        b.beginFill(0xffee00, 1);
        b.drawCircle(0, 0, entity.radius);
        b.endFill();
        b.x = entity.position.x
        b.y = -entity.position.y
        this.entityLayer.addChild(b)
    }

    _tween(obj, to) {
        this.tweens.push(new TWEEDLE.Tween(obj).to(to, this.frameSpeed).start())
    }
}
