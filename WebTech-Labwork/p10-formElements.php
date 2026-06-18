<?php
$name = $email = $gender = "";
$interests = [];
if($_SERVER["REQUEST_METHOD"] == "POST"){
    $name     = $_POST["name"];
    $email    = $_POST["email"];
    $gender   = $_POST["gender"];
    $interests = isset($_POST["interests"]) ? $_POST["interests"] : [];
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>PHP Form Elements</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 450px;
            margin: 50px auto;
        }
        input[type="text"],
        input[type="email"] {
            width: 100%;
            padding: 8px;
            margin: 5px 0 15px 0;
            box-sizing: border-box;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        input[type="submit"] {
            background-color: #4CAF50;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 15px;
        }
        .result {
            margin-top: 25px;
            background-color: #f0f0f0;
            padding: 15px;
            border-left: 5px solid #4CAF50;
            border-radius: 4px;
        }
    </style>
</head>
<body>
<h2>PHP Form Elements</h2>
<form method="POST" action="p10-formElements.php">
    <label>Name:</label>
    <input type="text" name="name" 
           placeholder="Enter your name..." 
           value="<?php echo $name; ?>">
    <label>Email:</label>
    <input type="email" name="email" 
           placeholder="Enter your email..." 
           value="<?php echo $email; ?>">
    <label>Gender:</label><br>
    <input type="radio" name="gender" value="Male"
        <?php if($gender == "Male") echo "checked"; ?>> Male
    <input type="radio" name="gender" value="Female"
        <?php if($gender == "Female") echo "checked"; ?>> Female
    <input type="radio" name="gender" value="Other"
        <?php if($gender == "Other") echo "checked"; ?>> Other
    <br><br>

    <label>Interests:</label><br>
    <input type="checkbox" name="interests[]" value="Programming"
        <?php if(in_array("Programming", $interests)) echo "checked"; ?>> Programming<br>
    <input type="checkbox" name="interests[]" value="Reading"
        <?php if(in_array("Reading", $interests)) echo "checked"; ?>> Reading<br>
    <input type="checkbox" name="interests[]" value="Traveling"
        <?php if(in_array("Traveling", $interests)) echo "checked"; ?>> Traveling<br>
    <input type="checkbox" name="interests[]" value="Gaming"
        <?php if(in_array("Gaming", $interests)) echo "checked"; ?>> Gaming<br>
    <br>
    <input type="submit" value="Submit">
</form>

<?php if($_SERVER["REQUEST_METHOD"] == "POST"): ?>
    <div class="result">
        <h3>Form Submission Results</h3>
        <p><strong>Name:</strong> <?php echo $name; ?></p>
        <p><strong>Email:</strong> <?php echo $email; ?></p>
        <p><strong>Gender:</strong> <?php echo $gender != "" ? $gender : "Not selected"; ?></p>
        <p><strong>Interests:</strong>
            <?php
                if(!empty($interests)){
                    echo implode(", ", $interests);
                } else {
                    echo "No interests selected.";
                }
            ?>
        </p>
    </div>
<?php endif; ?>
</body>
</html>