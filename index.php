<?php

	include("connect.php"); 	
	
	$link=Connection();

	$result=mysql_query("SELECT * FROM `tempLog` ORDER BY `timeStamp` DESC limit 300",$link);
	$data=array();
	
	  if($result!==FALSE){
		     while($row = mysql_fetch_array($result)) {
				array_push($data,$row);
		     }
		     	 mysql_free_result($result);
		     mysql_close();
		 }
?>

<html>
   <head>
      <title>Radish AI Temperature Sensor Data</title>

   </head>
<body>
   <h1>Radish AI Temperature sensor readings</h1>
<style>

.chart div {
  font: 10px sans-serif;
  background-color: steelblue;
  text-align: right;
  padding: 3px;
  margin: 1px;
  color: white;
}

</style>
<div class="chart"></div>
<script src="//d3js.org/d3.v3.min.js"></script>
   
<script>
 var data = <?php echo json_encode($data); ?>;

var x = d3.scale.linear()
    .domain([0, 60])
    .range([0, 420]);

d3.select(".chart")
  .selectAll("div")
    .data(data)
  .enter().append("div")
    .style("width", function(d) { return x(d.temperature) + "px"; })
    .text(function(d) { return d.timeStamp + " ----------     " +d.temperature; });

</script>


</body>
</html>
