<?php
session_start();
?>
<html>
<head>
<title>The Tiger King!!! </title>
</head>
<body bgcolor="black">
<p>
<img src="ncert.png" alt="NCERT" style="float:right; width:80px; height:80px; margin-right: 20px">
</p>
<center>
	<b><font color="plum" size="40px">THE TIGER KING !!! </font></b>
	<br>
	<br>
	<br>
	
		<form action="connect.php" method="post" id="form1">
<input type="text" name="fname" size="50" height="48" value="<?php echo $_SESSION['answer'] ?>"><br>
</form>

</p>
<div style=" width:40% ; height:80% ; background-image: url(p1.jpg); background-size : cover; color:lightyellow; font-size : 70px; padding-bottom:30px;">
</center>
</html>