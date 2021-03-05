window.onload = function() {
	const stema = document.getElementById('stema');
	const stema1 = document.getElementById('stema1');

	stema.addEventListener("change", schimbareTema);
	stema1.addEventListener("change", schimbareTema);

	function schimbareTema(){
		if(localStorage.tema == 0){
			localStorage.tema = 1;
		}
		else {
			localStorage.tema = 0;
		}
		aplicareTema();
	}

	function aplicareTema() {
		if (localStorage.tema == 1) {
				document.getElementById("stema").checked = true;
				document.getElementById("stema1").checked = true;
        document.getElementById("prezentare").id="prezentareLight";
				document.getElementById("boxes").style.backgroundImage = "url('./imagini/bg4.jpg')";
				document.getElementById("boxes").style.textShadow = "1px 1px 1px #000000";
    } else {
        document.getElementById("prezentareLight").id = "prezentare";
				document.getElementById("boxes").style.backgroundImage = "url('./imagini/cinema.jpg')";
				document.getElementById("boxes").style.textShadow = "0px 0px 0px";
    }
	}
	aplicareTema();
}
