<footer>

</footer>


</body>

      
 
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.5/js/bootstrap.min.js" integrity="sha384-BLiI7JTZm+JWlgKa0M0kGRpJbF2J8q+qreVrKBC47e3K6BW78kGLrCkeRX6I9RoK" crossorigin="anonymous"></script>


      <?php

       if(isset($pageRequirements)){
        
            $jsFiles = $pageRequirements->getFiles("js");
         
       }





      if(isset($jsFiles)){
         foreach ($jsFiles as $fileName) {
            echo '<script async src="/' . $fileName . '"></script>';
         }
      }
      
      echo '</html>';