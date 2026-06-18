<?php
$username = $phone = $email = "";
$userErr = $phoneErr = $emailErr = "";
$success = "";

if($_SERVER["REQUEST_METHOD"]=="POST"){
    $username = $_POST["username"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];

    //Username Validation
    if(empty($username)){
        $userErr = "Username cannot be empty.";
    }else{
        $username = trim($username);
    }

    //Email Validation
    if(empty($email)){
        $emailErr = "Email is required!";
    }else{
        $email = trim($email);
        if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
            $emailErr = "Invalid email format!";
        }
    }

    //Phone Validation
    if(empty($phone)){
        $phoneErr = "Phone number can't be empty!";
    }else{
        $phone = trim($phone);
        if(!preg_match("/^(98|97)[0-9]{8}$/", $phone)){
            $phoneErr = "Phone number must start with 98 or 97 and of 10 digits";
        }
    }
    if($userErr =="" && $emailErr =="" && $phoneErr ==""){
        $success = "Form Submitted Successfully!";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Form Validation</title>
    <style>
        .error{
            color: red;
            font-size: 13px;
        }
        .success{
            color: green;
            font-bold: bold;
        }
    </style>
</head>
<body>
    <h2>Form Validation with PHP</h2>
    <?php if($success != ""): ?>
        <p class= "success"><?php echo $success; ?></p>
        <p>Username: <?php echo $username; ?></p>
        <p>Email: <?php echo $email; ?></p>
        <p>Phone: <?php echo $phone; ?></p>
    <?php endif; ?>

    <form method="POST" action="p7-formValidate.php">
        <label>Username:</label><br>
        <input type="text" name="username" value="<?php echo $username; ?>" placeholder="Enter Useename..."><br>
        <span class="error"><?php echo $userErr; ?></span><br>

        <label>Email:</label><br>
        <input type="text" name="email" value="<?php echo $email; ?>" placeholder="Enter Email..."><br>
        <span class="error"><?php echo $emailErr; ?></span><br>

        <label>Phone:</label><br>
        <input type="text" name="phone" value="<?php echo $phone; ?>" placeholder="Enter Phone Number..."><br>
        <span class="error"><?php echo $phoneErr; ?></span><br>

        <input type="submit" value="Submit">
    </form>
</body>
</html>