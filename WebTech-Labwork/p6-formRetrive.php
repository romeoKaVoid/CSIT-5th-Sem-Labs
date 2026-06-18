<?php
$username = "";
$email = "";
$phone = "";
if($_SERVER["REQUEST_METHOD"] == "POST"){
    $username = $_POST["username"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Form Retrieval</title>
</head>
<body>
    <h2>Simple Form to be Submitted</h2>

    <form method="POST" action="p6-formRetrive.php">
        <label>Username: </label> <br>
        <input type="text" name="username" placeholder="Enter Username..."><br><br>

        <label>Email: </label><br>
        <input type="email" name="email" placeholder="Enter email..."><br><br>

        <label>Phone: </label> <br>
        <input type="text" name="phone" placeholder="Enter Phone Number..."><br><br>

        <input type="submit" value="Submit">
    </form>

    <?php if($username != ""): ?>
        <h3>Submitted Data:</h3>
        <p>Username: <?php echo $username; ?></p>
        <p>Email: <?php echo $email; ?></p>
        <p>Phone: <?php echo $phone; ?></p>
    <?php endif; ?>
</body>
</html>