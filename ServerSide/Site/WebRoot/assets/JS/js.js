// JS Script
$(document).ready(function(){

var cardMark = 4;
var singleCardWidth;
var cardCount = 5;

$('.testMasterContainer').scroll(function(){
	
	var masterWidth = $('.itemCardContainer').css('width').match(/\d+/)[0]; // "3";
	console.log('master Width: ' + masterWidth);
	var marginWidth = (masterWidth / cardCount) / 20; //100 / ((cardCount + 5) * 20)
	console.log('Marginw: ' + marginWidth);
	singleCardWidth = (masterWidth - ( cardCount * (marginWidth) ) ) / cardCount;
	console.log("scw: " + singleCardWidth);
	var cardNo = Math.round( $('.testMasterContainer').scrollLeft() / singleCardWidth ) + 1;

    $('.card-title').html(cardNo);


    if(cardNo > cardMark){

    	cardMark = cardMark + 4;

    	cardCount = $('.card').length;

    	var newWidth = 100 * ( cardCount + 5);//singleCardWidth * ( cardCount + 4);

    	cardCount = cardCount + 5;


    	//Server REST requests will be here later....
    	$( "#thisONE" ).clone().appendTo( '.card-deck' );
    	$( "#thisONE" ).clone().appendTo( ".card-deck" );
    	$( "#thisONE" ).clone().appendTo( ".card-deck" );
    	$( "#thisONE" ).clone().appendTo( ".card-deck" );
    	$( "#thisONE" ).clone().appendTo( ".card-deck" );

    	$('.itemCardContainer').css('width', newWidth + '%');
    	$('.card').css('width', 100 / (cardCount +  (cardCount / 5)) + '%');
    	$('.card').css('margin-left', 100 / ((cardCount) * 20) + '%');


    }


    
});






});




