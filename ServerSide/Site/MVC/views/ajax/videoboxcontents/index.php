<?php
/**
 * This handles the ajax requests for the video box contents from the accs page(s).
 *
 * @author   <robert@robertcurran.co.uk> Robert Curran
 * @date 	23/6/2016
 */

//Include the experimental html tag functions
include($_SERVER['DOCUMENT_ROOT'].'/../PHPIncludes/Libraries/HTMLTagExperimental.php');

//Display contents of the tutorial video box:			
include($_SERVER['DOCUMENT_ROOT'].'/../PHPIncludes/Views/pages/home/INC_VideoBlock.php');

