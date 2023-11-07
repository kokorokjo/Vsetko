// let worldPlayers = {}
// let worldBullets = {}
// let worldBorder = null

const TESTFrame = {
    players: [
        {
            x: 1.34,
            y: 3.2,
            angle: 23,
            alive: true,
            id: 1,
            name: "hrac",
            tank_id: 1,
            tank_radius: 10,
        }
    ],
    bullets: [
        {
            position: {
                x: 20.34,
                y: 13.2,
            },
            id: 1,
            shooter_id: 1,
            radius: 3,
        },
    ],
}

function hsl2rgb(h,s,l) {
  let a= s*Math.min(l,1-l);
  let f= (n,k=(n+h/30)%12) => l - a*Math.max(Math.min(k-3,9-k,1),-1);
  return Math.ceil(f(0) * 0xFF) * 0x10000 + Math.ceil(f(8) * 0xFF) * 0x100 + Math.ceil(f(4) * 0xFF);
}

function playerColor(id) {
    return hsl2rgb(360 / game.frames[0].players.length * id, 0.8, 0.5)
}

