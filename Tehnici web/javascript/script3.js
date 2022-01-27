window.onload = function() {
	const stema = document.getElementById('stema');
	const stema1 = document.getElementById('stema1');
	const buton = document.getElementById('buton-newsletter');
	const body = document.body;
	var listaMailuri = [];
	var nrfilme = document.getElementsByClassName('film').length;

	stema.addEventListener("change", schimbareTema);
	stema1.addEventListener("change", schimbareTema);
	buton.addEventListener("click", newsletter);
	body.addEventListener("keydown", afisareMailuri);


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
				document.getElementById("oferta").style.backgroundImage = "url('./imagini/bg4.jpg')";
				for(i = 0; i < nrfilme; i++) {
    			document.getElementsByClassName('film')[i].getElementsByTagName('img')[0].style.borderStyle="solid";
					document.getElementsByClassName('film')[i].getElementsByTagName('img')[0].style.borderColor="#E67C7C";
				}

    } else {
        document.getElementById("prezentareLight").id = "prezentare";
				document.getElementById("oferta").style.backgroundImage = "url('./imagini/cinema.jpg')";
				for(i = 0; i < nrfilme; i++) {
    			document.getElementsByClassName('film')[i].getElementsByTagName('img')[0].style.borderStyle="none";
				}
    }
	}
	aplicareTema();



	function newsletter(e){
		var testEmail = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
		var inputEmail= document.getElementById("email").value;

		if (inputEmail.length<=0){
			var eroare = document.createElement("P");
			eroare.innerHTML = "Nu ati introdus nimic!";
			document.getElementById("newsletter").appendChild(eroare);
			e.preventDefault();
			setTimeout(function(){ document.getElementById("newsletter").removeChild(eroare); }, 2000);
		}
		else if(!testEmail.test(inputEmail)){
			var eroare = document.createElement("P");
			eroare.innerHTML = "Nu ati introdus o adresa valida!";
			document.getElementById("newsletter").appendChild(eroare);
			e.preventDefault();
			setTimeout(function(){ document.getElementById("newsletter").removeChild(eroare); }, 2000);
		}
		else{
			localStorage.setItem("email", inputEmail);
			listaMailuri.push(inputEmail);
			var ziua = new Date();
			alert('Iti multumim ca te-ai abonat, '+localStorage.email.replace(localStorage.email.slice(localStorage.email.indexOf("@")),"")+'\nData de azi: '+ziua.getDate()+'.'+(ziua.getMonth()+1)+'.'+ziua.getFullYear());
			e.preventDefault();
			document.getElementById("email").value="";
		}
	}

	function afisareMailuri(tasta){
		if(tasta.ctrlKey && tasta.key === 'm'){
			if(listaMailuri.length == 0){
				alert("Nu s-a introdus inca niciun e-mail");
			}
			else{
				alert(listaMailuri.join("\n"));
			}
		}
	}
}
