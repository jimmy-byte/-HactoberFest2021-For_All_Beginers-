let color1 = document.getElementById("color1");
let color2 = document.getElementById("color2");
let css = document.querySelector(".content");
let body = document.getElementById("body");

function codeGenerate(){
    body.style.background = `linear-gradient(to left,${color1.value},${color2.value})`;
    css.textContent = body.style.background;
}

color1.addEventListener("input", codeGenerate);
color2.addEventListener("input", codeGenerate);