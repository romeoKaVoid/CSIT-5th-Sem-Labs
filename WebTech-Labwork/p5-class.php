<?php
class book{
    public $title;
    public $author;
}
$book1 = new book();
$book1->title = "Atomic Habits";
$book1->author = "James Clear";

$book2 = new book();
$book2-> title = "Muna Madan";
$book2-> author = "Laxmi Prasad Devkota";

echo $book1->title." written by ".$book1->author."<br>";
echo $book2->title." written by ".$book2->author;

?>