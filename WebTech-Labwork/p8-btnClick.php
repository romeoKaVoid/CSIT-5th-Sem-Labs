<?php
$message = "";

if($_SERVER["REQUEST_METHOD"] == "POST"){

    if(isset($_POST["greet"])){
        $message = "Hello! Welcome to PHP Button Click Event!";
    }
    if(isset($_POST["reset"])){
        $message = "";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Button Click Event</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 400px;
            margin: 60px auto;
            text-align: center;
        }
        button {
            padding: 10px 20px;
            font-size: 15px;
            border: none;
            border-radius: 5px;
            color: white;
        }
        .btn-greet  { background-color: #4CAF50; }
        .btn-reset  { background-color: #f44336; }
        .message {
            margin-top: 25px;
            padding: 15px;
            background-color: #f0f0f0;
            border-left: 5px solid #4CAF50;
            font-size: 18px;
            border-radius: 5px;
        }
    </style>
</head>
<body>

    <h2>PHP Button Click Event</h2>
    <p>Click any button to see a message!</p>

    <form method="POST" action="p8-btnClick.php">
        <button type="submit" name="greet" class="btn-greet">
            Say Hello
        </button>
        <button type="submit" name="reset" class="btn-reset">
            Reset
        </button>
    </form>

    <?php if($message != ""): ?>
        <div class="message">
            <?php echo $message; ?>
        </div>
    <?php endif; ?>
</body>
</html>