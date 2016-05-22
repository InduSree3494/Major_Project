<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
<style>
body{
      background-image:url("b.jpg");
      color:DarkSalmon;
      background-attachment:fixed;    
     }

#subhead {
            font-size:18px;
            color:GoldenRod;
          }

#header{ text-align:center;
          margin-top:20px; 
       }

#wel
{
  float:right;
  margin-right:350px;
  margin-top:-300px;
}

#header1
{
  color:LightPink;
  margin-left:150px;
  font-size:19px;
}

#rad {  padding: 5px;
  border: solid 1px #dcdcdc;
  transition: box-shadow 0.3s, border 0.3s;
  border-radius:5px;
  width:240px;}

#fill_in
{
  margin-left:300px;
  margin-top:50px;
}

#sub 
  { 
    margin-left:285px;
     padding: 5px;
  border: solid 1px #dcdcdc;
  transition: box-shadow 0.3s, border 0.3s;
  border-radius:5px;
  width:240px;
}

#menu { position:fixed;
		float:left;
        margin-top:-10px;
      }
	  
#menu ul {
    width: 100%;
    padding: 0;
    list-style-type: none;
    text-align:center;
}

#menu a {
    display:block;
    width: 100px;
    height:50px;
    text-decoration: none;
    color: white;
    background-color: DarkOliveGreen;
    padding: 0.7em 0.2em;
    border: 2px solid #8AC007;
    border-radius: 8px;
}

#menu a:hover {
    background-color:Darkkhaki;
}

#footer {
    background-color:rgb(32,32,32);
    color:white;
   
    text-align:center;
   padding:2px;	
   margin-top:110px; 	 
}

#footer a{
	  text-decoration:underline;
	  color:green;
         }
.error {color:orangered;}
	 
</style>
</head>
<body>
<?php

$name=$email="";
//input validation
		
		function validate_form()
		{
			$error=0;
			global $name,$email;
			global $error_name,$error_email;
		    $name=$_POST['fname']; 
		    return $error;
		}
	
if ($_SERVER["REQUEST_METHOD"]== "POST")
	  { 
		if (isset($_POST['Submit']))
		{  $error=validate_form();
		   if (!$error)
		   {$host="localhost";

			$user="root";
			$password="ricochet^6C";
			$con=mysqli_connect($host,$user,$password);

        if (!$con)
	       die("Oh Snap!! Unable to connect to our server");
        else
	    {
		mysqli_select_db($con,"question");
		$email="rt";
												/*$query="INSERT INTO specific_table VALUES('{$name}','{$email}');";*/
												/* $query="INSERT INTO specific_table VALUES('$name','$email');"; */
		$query="SELECT answer FROM specific_table WHERE question LIKE '$name'";
		$result=mysqli_query($con,$query);
		$var=mysqli_fetch_assoc($result);
		$my_id=$var['answer'];
		$_SESSION['answer']=$my_id;
		header("location:response.php");
		 
		//Cast this into int to protect yourself against sql injection
		//echo "<h1>$my_id</h1>";
		mysqli_close($con);
		  
		}
		}
	  }
	  }
?>