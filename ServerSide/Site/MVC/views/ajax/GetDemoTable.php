<?php
//Get demo table



if(($_SERVER['REQUEST_METHOD'] == "POST")){

	$RunID =  Run::getLatestRunID();

	$Run = new Run($RunID , '');

	$RunData = $Run->getRunData();

	echo '<table id="dataTable1" class="table table-striped table-hover"><thead><tr>';

	echo '<th>#</th>';

	foreach ($RunData[0] as $key => $value) {
			
			echo '<td>' . $key .'</td>';
		
	}

	echo '</tr></thead><tbody>';



	$rowID = 0;
	
	foreach ($RunData as $row) {
		
		echo '<tr><th scope="row">' . $rowID++ . '</th>';

		foreach ($row as $key => $value) {
			
			echo '<td>' . $value .'</td>';
		
		}

		echo '</tr>';


	}

		echo '<tr id="scrollTarget"><td></td></tr>';
	echo '</tbody></table>';



	//Finished
	die();

}else{
	
	//Not a post request.. Unexpected
	echo 'Must Buy Dog Biscuits';
	die();

}