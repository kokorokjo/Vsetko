const urlParams = new URLSearchParams(window.location.search)
const renderer = new Renderer()
const game = new Game(renderer)

if (urlParams.has("file")) {
    document.getElementById("js-file").style.display = "none"
    game.loadUrl(urlParams.get("file"))
}

document.getElementById("js-speed").addEventListener("change", (e) => {
    game.renderer.frameSpeed = parseInt(e.target.value)
})

document.getElementById("js-slider").addEventListener("input", (e) => {
    game.nextFrameId = parseInt(e.target.value)
})

document.getElementById("js-play").addEventListener("click", (e) => {
    game.startPlayback()
})

document.getElementById("js-pause").addEventListener("click", (e) => {
    game.stopPlayback()
})

document.addEventListener("keydown", (e) => {
    if (e.code === "Space") {
        if (game.playing) {
            game.stopPlayback()
        } else {
            game.startPlayback()
        }
        e.preventDefault()
    }

    if (e.code === "ArrowLeft") {
        if (game.playing) {
            return
        }
        game.frame = Math.max(game.frame-1, 0)
        game.nextFrameId = game.frame
        game.nextFrame()
        e.preventDefault()
    }
    if (e.code === "ArrowRight") {
        if (game.playing) {
            return
        }
        game.frame = Math.min(game.frame+1, game.frames.length-1)
        game.nextFrameId = game.frame
        game.nextFrame()
        e.preventDefault()
    }
})
