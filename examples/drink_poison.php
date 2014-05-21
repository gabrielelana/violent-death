<?php

require __DIR__ . "/../vendor/autoload.php";

// The output will be something like:
//
// What is this? Should I drink it?
// There, I drank it, I will die eventually...
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// Still there :-)
// [1]    26584 segmentation fault (core dumped)  php examples/drink_poison.php

echo "What is this? Should I drink it?\n";
drink_poison($msToTakeEffect=500, $msToAgonizeAtMost=1000);
// Here we have created a background thread that will wait
// at least for 500ms and at most 1500ms before to cause
// an horrible death with a segmentation fault

echo "There, I drank it, I will die eventually...\n";
while(true) {
    echo "Still there :-)\n";
    usleep(50000);
}
