<?php
$filename = "content.txt";

// READ the file
$content = file_get_contents($filename);
echo "Original Content: " . $content . "<br>";

// MODIFY the content
$modified = $content . " This line was added by PHP.";
$modified = str_replace("original", "modified", $modified);

// WRITE back to file
file_put_contents($filename, $modified);

// READ again to confirm
$updated = file_get_contents($filename);
echo "Updated Content: " . $updated . "<br>";

?>