<?php
/**
 * All of the pages on this site should be listed here, the page header and footer should be configuired with pageRequirements object and requested by each page.
 * 
 */
  class DashController {

    public function home() {

      //Require the class for storing CSS and Script requirements:
      require_once($_SERVER['DOCUMENT_ROOT'] . '/../PHPIncludes/pageLinkScriptsCSS.php');

      //Make an object of the pageLinkScriptsCSS class for storing the CSS requirements for the header:
      $pageRequirements = new pageLinkScriptsCSS();
      
      $pageRequirements->add("css", ['DashStyles.css','animate.min.css']);

      $pageRequirements->add("title", 'DashBorad');

      $pageRequirements->add("js", ['assets/JS/dashHome.js']);



      callStructural('header','stdBS2',$pageRequirements);

      require_once('views/dash/home.php');

      //Render the page footer:
      callStructural("footer", 'stdBS2', $pageRequirements); 


    }


    public function error() {

   //Require the class for storing CSS and Script requirements:
    require_once($_SERVER['DOCUMENT_ROOT'] . '../PHPIncludes/pageLinkScriptsCSS.php');

    $pageRequirements = new pageLinkScriptsCSS();

    $pageRequirements->add("css", ['error.css']);

    $pageRequirements->add("title", 'The Sky Is Falling');

    callStructural('header','std',$pageRequirements);

    require_once('views/pages/error.php');

      //Render the page footer:
    callStructural("footer", 'std', $pageRequirements); 

    }
  }
?>
