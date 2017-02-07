<?php
//Handles the creation of a new log datum

if(($_SERVER['REQUEST_METHOD'] == "POST")){



 // $WallClock ,  $Opto0 , $Opto1 , $Opto2 , $Opto3 , $Opto4 , $Opto5 , $Opto6 , $Opto7 , $Opto8  , $WheelLAngSpeed , $WheelRAngSpeed  , $MotorRSetPoint , $MotorLSetPoint );


	//Get the clean post data
	
	$RunID = filter_var($_POST['RunID'] , FILTER_SANITIZE_STRING);
	$WallClock = filter_var($_POST['WallClock'] , FILTER_SANITIZE_STRING);
	
	$Opto0 = filter_var($_POST['Opto0'] , FILTER_SANITIZE_STRING);
	$Opto1 = filter_var($_POST['Opto1'] , FILTER_SANITIZE_STRING);
	$Opto2 = filter_var($_POST['Opto2'] , FILTER_SANITIZE_STRING);
	$Opto3 = filter_var($_POST['Opto3'] , FILTER_SANITIZE_STRING);
	$Opto4 = filter_var($_POST['Opto4'] , FILTER_SANITIZE_STRING);
	$Opto5 = filter_var($_POST['Opto5'] , FILTER_SANITIZE_STRING);
	$Opto6 = filter_var($_POST['Opto6'] , FILTER_SANITIZE_STRING);
	$Opto7 = filter_var($_POST['Opto7'] , FILTER_SANITIZE_STRING);
	$Opto8 = filter_var($_POST['Opto8'] , FILTER_SANITIZE_STRING);


	$WheelLAngSpeed = filter_var($_POST['WheelLAngSpeed'] , FILTER_SANITIZE_STRING);
	$WheelRAngSpeed = filter_var($_POST['WheelRAngSpeed'] , FILTER_SANITIZE_STRING);
	$MotorRSetPoint = filter_var($_POST['MotorRSetPoint'] , FILTER_SANITIZE_STRING);
	$MotorLSetPoint = filter_var($_POST['MotorLSetPoint'] , FILTER_SANITIZE_STRING);


	$Log =  Log::attemptCreateNew( $RunID , $WallClock ,  $Opto0 , $Opto1 , $Opto2 , $Opto3 , $Opto4 , $Opto5 , $Opto6 , $Opto7 , $Opto8  , $WheelLAngSpeed , $WheelRAngSpeed  , $MotorRSetPoint , $MotorLSetPoint );


	//Finished
	die();

}else{
	
	//Not a post request.. Unexpected
	echo 'Must Buy Dog Biscuits';
	die();

}