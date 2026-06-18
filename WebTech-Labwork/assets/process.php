<?php

$x = $_GET['x'];
$y = $_GET['y'];

// Computer Area (Rectangle)
// coords="34,44,270,350"
if ($x >= 34 && $x <= 270 && $y >= 44 && $y <= 350) {
    echo "<h1>You clicked on Computer 💻</h1>";
}

// Phone Area (Rectangle)
// coords="290,172,333,250"
elseif ($x >= 290 && $x <= 333 && $y >= 172 && $y <= 250) {
    echo "<h1>You clicked on Phone 📱</h1>";
}

// Coffee Area (Circle)
// coords="337,300,44"
elseif ((($x - 337)*($x - 337) + ($y - 300)*($y - 300)) <= (44*44)) {
    echo "<h1>You clicked on Coffee ☕</h1>";
}

else {
    echo "<h1>You clicked somewhere else!</h1>";
}

?>