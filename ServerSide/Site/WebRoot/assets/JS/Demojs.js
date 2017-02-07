//Demo Page JS
$(document).ready(function(){

//ajax grab from server, dump on page

numRows = 0;
timer = setInterval(getData, 100);

function getData() {

$.ajax({
			url: "/ajax/getdemodatatable",
			type: "POST",
			data: 'cake!',
			cache: false,
			success: function(reternedData) {

				$('#dataTableTarget').html(reternedData);
				
				if( $('#dataTable1 >tbody >tr').length != numRows  ){

					numRows = $('#dataTable1 >tbody >tr').length;

					$('html, body').animate({
        				scrollTop: $('#scrollTarget').offset().top
    				}, 50);

				}


			}

		});





}


});


