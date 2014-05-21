<?php

/**
 * It will create a segmentation fault at least after `$msToTakeEffect`
 * milliseconds and at most after `$msToTakeEffect + $msToAgonizeAtMost`
 * milliseconds. This will happen asynchronously in a background thread so
 * that after this call the code can continue it's normal flow
 *
 * @param integer $msToTakeEffect How many milliseconds to wait before the
 *   poison takes effect
 * @param integer $msToAgonizeAtMost At most how many milliseconds to wait
 *   before the poison will end your code. Default `0`
 * @param integer $probabilityToDie The percentage of probability to die. An
 *   integer `1` and `100`. Default `100`
 * @param integer $probabilityToDie The percentage of probability to die. An
 *   integer `1` and `100`. Default `100`
 *
 * @return void
 */
function drink_poison(
    $timeToTakeEffect, $howLongYouWillAgonizeAtMost=0,
    $probabilityToDie=100, $functionToCauseDeath='die_violently_after'
)
{
    if (!is_callable($functionToCauseDeath)) {
        throw new Exception('Expected a callable element as last parameter');
    }

    $probabilityToDie = is_bool($probabilityToDie) ? 100 : $probabilityToDie;
    $probabilityToDie = $probabilityToDie < 1 ? $probabilityToDie * 100 : $probabilityToDie;
    $probabilityToDie = min(100, max(1, $probabilityToDie));

    if (mt_rand(1, 100) <= round($probabilityToDie)) {
        $functionToCauseDeath(
            $timeToTakeEffect + rand(0, $howLongYouWillAgonizeAtMost)
        );
    }
}

function play_russian_roulette($probabilityToDie=16, $functionToCauseDeath='die_violently')
{
    // TODO: to be implemented
}
