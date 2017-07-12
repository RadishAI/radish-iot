<?php

	function Connection(){
		$server="160.153.16.46";
		$user="radishiot";
		$pass="radishiot@123";
		$db="radishiot";
	   	
		$connection = mysql_connect($server, $user, $pass);

		if (!$connection) {
	    	die('MySQL ERROR: ' . mysql_error());
		}
		
		mysql_select_db($db) or die( 'MySQL ERROR: '. mysql_error() );

		return $connection;
	}
?>
