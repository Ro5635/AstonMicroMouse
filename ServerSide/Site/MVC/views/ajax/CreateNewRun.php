<?php
/*
* This Creates a new run
*
* 
 */


if(($_SERVER['REQUEST_METHOD'] == "POST")){

	

	//Create a new Run:
	$Run =  Run::attemptCreateNew();

	// Just assume that creation worked for now and continue
	
	error_log('New run created with the ID: ' . $Run->runID);
	
	$jsonArray = array( 'RunID' => $Run->runID  );

	echo json_encode($jsonArray);

	//Finished
	die();

}else{
	
	//Not a post request.. Unexpected
	echo 'Must Buy Dog Biscuits';
	die();

}

