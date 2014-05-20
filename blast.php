<?php

$module = 'blast';
if(!extension_loaded('blast')) {
    dl($module . '.' . PHP_SHLIB_SUFFIX);
}
$functions = get_extension_funcs($module);
echo "Functions available in the {$module} extension:" . PHP_EOL;
foreach($functions as $function) {
    echo "\t- $function" . PHP_EOL;
}
echo PHP_EOL;

echo 'call die_violently' . PHP_EOL;
die_violently();
