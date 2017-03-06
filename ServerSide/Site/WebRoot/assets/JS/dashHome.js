// Dash Home Js

$(document).ready(function(){


	$('.manDirectButt').click(function(){

		var directID = $(this).attr("data-directID");

		transmitManContDir(directID);

	});




	function transmitManContDir(directID){

		$.ajax({
			url: "/ajax/manualcontrol",
			type: "POST",
			data: 'manDirectID=' + directID,
			cache: false,
			success: function(reternedData) {


			}

		});
	}






});