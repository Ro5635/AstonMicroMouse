<?php
// This model is responsible for handaling a Log.
//
// @author Robert Curran robert@robertcurran.co.uk

class Log {

	public $runID;
	public $dateTime;



	public function __construct($runID, $dateTime) {
		
		//Set the instance variables
		$this->runID = $runID;
		$this->dateTime = $dateTime;




	}



	public static function attemptCreateNew($RunID, $WallClock ,  $Opto0 , $Opto1 , $Opto2 , $Opto3 , $Opto4 , $Opto5 , $Opto6 , $Opto7 , $Opto8  , $WheelLAngSpeed , $WheelRAngSpeed  , $MotorRSetPoint , $MotorLSetPoint ) {



		$db = Db::getInstance();

		$tableName = 'Run_' . $RunID;

		//Insert the new datum into the relevent log table:
		$req = $db->prepare('INSERT INTO ' . $tableName . ' ( WallClock ,  Opto0 , Opto1 , Opto2 , Opto3 , Opto4 , Opto5 , Opto6 , Opto7 , Opto8  , WheelLAngSpeed , WheelRAngSpeed  , MotorRSetPoint , MotorLSetPoint ) VALUES( :WallClock ,  :Opto0 , :Opto1 , :Opto2 , :Opto3 , :Opto4 , :Opto5 , :Opto6 , :Opto7 , :Opto8  , :WheelLAngSpeed , :WheelRAngSpeed  , :MotorRSetPoint , :MotorLSetPoint  )');
		$req->execute(array( ':WallClock' => $WallClock , ':Opto0' => $Opto0 , ':Opto1' => $Opto1 , ':Opto2' => $Opto2 , ':Opto3' => $Opto3 , ':Opto4' => $Opto4 , ':Opto5' => $Opto5 , ':Opto6' => $Opto6 , ':Opto7' => $Opto7 , ':Opto8' => $Opto8 , ':WheelLAngSpeed' => $WheelLAngSpeed , ':WheelRAngSpeed' => $WheelRAngSpeed , ':MotorRSetPoint' => $MotorRSetPoint , ':MotorLSetPoint' => $MotorLSetPoint  ) );

		
		return '';

		


	}



}