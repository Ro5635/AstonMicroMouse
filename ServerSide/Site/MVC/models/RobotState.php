<?php
// This model is responsible for handaling a Robots State.
//

class RobotState {

	public $runID;
	public $dateTime;



	public function __construct($runID, $dateTime) {
		
		
		if( Run::checkRunIDIsValid($runID) ){

			//Set the instance variables
			$this->runID = $runID;
			$this->dateTime = $dateTime;


		}else{

			error_log('Attempted To Access an non existing Run ID, attempted to access: ' . $runID);
			error_log('Abourting as likley a security violation');

			//Halt execution
			die();


		}



	}

	/**
	 * Attempt to create new Run
	 * @return Run, a new Run object
	 */
	public static function attemptCreateNew() {



		$db = Db::getInstance();


		//Get an unused RunID

		//Track the number of attempst to get a unique ID.
		$attemps = 0;
		//Random number to be used as the Customer ID: 
		$randomNumber;

		do {

			if($attemps > 5){
				//More than five atetmpts to get an unused ID, something is BADLY wrong.
				error_log("FATAL ERROR, Unable to find a unique Id for the new run");
				die();
			}

    		//Generate a psudo random number for use as the id, no need for crytographic randomness, not thsi does pose a limuit on the number of custoemrs! :)
			$randomNumber = rand(1000000, 99999999);

			//Check to see that the index is not in use:

			$req = $db->prepare('SELECT * FROM Runs WHERE RunID = :ID limit 5');
			$req->execute(array(':ID' => $randomNumber));
			$Usersfound = $req->fetchAll();

			$attemps++;

		} while (count($Usersfound)  > 0);


		//Found new unused RunID
		$newRunID = $randomNumber;



		//Insert the new run into the runs table:
		$req = $db->prepare('INSERT INTO Runs (RunID) VALUES( :newRunID )');
		$req->execute(array( ':newRunID' => $newRunID) );



		//Create the new run table:

		$newTableName = 'Run_' . $newRunID;

		//TEMPAORY IMPLEMENTATION!
		//NB Table name is generated on server so is safe for the non PDO use
		$req = $db->prepare('CREATE TABLE ' . $newTableName  .'( DatumID int unsigned auto_increment primary key,  WallClock int unsigned  NOT NULL , CreatedAT timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP , Opto0 int, Opto1 int, Opto2 int, Opto3 int, Opto4 int, Opto5 int, Opto6 int, Opto7 int, Opto8 int , WheelLAngSpeed int, WheelRAngSpeed int , MotorRSetPoint int, MotorLSetPoint int )');
		$req->execute();



		//get the new account
		$newAccount = new  Run( $newRunID , 'TO_DO');

		//return the new account
		return $newAccount;


	}

	/**
	 * This gets all of the data points for a supplied runID
	 * @param  [type] $runID [description]
	 * @return [type]        [description]
	 */
	public function getRunData(){

		$tableName = 'Run_' . $this->runID;

		$db = Db::getInstance();

		$req = $db->prepare('Select *  FROM ' . $tableName);	
		$req->execute();
		$runData = $req->fetchAll();

		return $runData;


	} 

	public function checkRunIDIsValid($runID){

		$db = Db::getInstance();

		$req = $db->prepare('SELECT * FROM Runs WHERE RunID = :runID');	
		$req->execute( array( ':runID' => $runID ) );
		$runsFound = $req->fetchAll();

		if(count($runsFound) == 1){

			
			return True;
			

		}else{

			return False;

		}

	}

	/**
	 * Gets the latest created RunID
	 * @return Int Run ID  (No handaling of not found)
	 */
	public static function getLatestRunID(){

		$db = Db::getInstance();

		$req = $db->prepare('SELECT * FROM Runs ORDER BY CreatedAt DESC limit 1');	
		$req->execute();
		$runIDsFound = $req->fetch();

		return $runIDsFound['RunID'];



	}



}