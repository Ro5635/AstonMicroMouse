<?php
class ajaxController {


/**
 * Handle the login attempt
 * @return [type] [description]
 */
	public function login() {

	    //Model:
		require_once('../MVC/models/Login.php');
		require_once('../MVC/models/Account.php');

		//view:
		require_once('views/ajax/loginHandle.php');


	}

	/**
	 * Handdle the attemt to create an account
	 * @return [type] [description]
	 */
	public function createaccount() {

	    //Model:
		require_once('../MVC/models/Account.php');

		//view:
		require_once('views/ajax/CreateAccount.php');


	}


	public function newrun(){
		
		//Model:
		require_once('../MVC/models/Run.php');

		//view:
		require_once('views/ajax/CreateNewRun.php');

	}



	public function log(){

		//Model:
		require_once('../MVC/models/Log.php');

		//view:
		require_once('views/ajax/NewLogDatum.php');

	}

	/**
	 * Allows the dashborad to mutate the manual control parameters
	 * @return [type] [description]
	 */
	public function manualcontrol(){
		


	}

	//THIS IS A TMP DEMO THAT GETS THE MOST RECENT TABLE
	public function getdemodatatable(){

		//Model:
		require_once('../MVC/models/Run.php');

		//view:
		require_once('views/ajax/GetDemoTable.php');


	}
	


}
