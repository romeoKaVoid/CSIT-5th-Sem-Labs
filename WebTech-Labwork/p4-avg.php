<?php
function avg($num){
    return array_sum($num) / count($num);
}
$arr = [15,6,21];
echo "The average of Array is ".avg($arr);
?>