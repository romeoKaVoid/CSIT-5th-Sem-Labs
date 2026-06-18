<?php
setcookie("user_pref","dark_mode",time()+3600,"/");
if(isset($_COOKIE["user_pref"])){
    echo "User Preference: ".$_COOKIE["user_pref"];
}
?>