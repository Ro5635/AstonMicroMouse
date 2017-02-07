<?php

/*
*	Dash Home
*
* 
 */


echo '<body>';

?>






<!-- Nav Bar -->

<nav class="navbar navbar-toggleable-md navbar-light bg-faded">
  <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <a class="navbar-brand" href="#">MicroMouse</a>

  <div class="collapse navbar-collapse" id="navbarSupportedContent">
    <ul class="navbar-nav mr-auto">
      <li class="nav-item active">
        <a class="nav-link" href="#">Dash <span class="sr-only">(current)</span></a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="#">Data Viewer</a>
      </li>
      <li class="nav-item">
        <a class="nav-link disabled" href="#">Export</a>
      </li>
    </ul>
    <form class="form-inline my-2 my-lg-0">
      <input class="form-control mr-sm-2" type="text" placeholder="Search Routine">
      <button class="btn btn-outline-success my-2 my-sm-0 disabled" type="submit">Run</button>
    </form>
  </div>
</nav>



<!-- End Nav bar -->

<div class="container">

	<!-- Page into -->
	<div class="row">

		<div class="jumbotron jumbotron-fluid">
			<div class="container">
				<h1 class="display-3">Live DashBoard</h1>
				<p class="lead">Control and monitor your micro mouse from here.</p>
			</div>
		</div>


	</div>


	<div class="form-group">
		&nbsp;
	</div>


	<div class="row marginFix">


		<div class="col-sm-5">

			<div class="row">
				
				
					 <h1 class="display-4 text-center nonBootStrapCentreThis">Manual Control</h1> 
				
				

			</div>

			<div class="row">

				<div class="col-sm-4"></div>
				<div class="col-sm-4 text-center">

					<button type="button"  data-directID="1" class="btn btn-primary btn-lg manDirectButt">🔺</button>

				</div>
				<div class="col-sm-4"></div>


			</div>



			<div class="row">

				<div class="col-sm-4 text-center">

					<button type="button" data-directID="3" class="btn btn-primary btn-lg manDirectButt">◀</button>

				</div>

				<div class="col-sm-4"></div>
				<div class="col-sm-4 text-center">

					<button type="button" data-directID="2"  class="btn btn-primary btn-lg manDirectButt">▶</button>


				</div>


			</div>


			<div class="row">

				<div class="col-sm-4"></div>
				<div class="col-sm-4 text-center">

					<button type="button" data-directID="4" class="btn btn-primary btn-lg manDirectButt">🔻</button>

				</div>
				<div class="col-sm-4"></div>


			</div>



		</div><!-- Close containg Row -->

		<div class="col-sm-7">



		</div>




	</div>
</div>