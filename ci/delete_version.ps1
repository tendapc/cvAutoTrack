﻿$version = Get-Content version.ver

$token="cvAutoTrackTmpToken"
$url='http://update.api.weixitianli.com/cvAutoTrack/Version?token='+$token+'?version='+$version
echo $url
Invoke-RestMethod -Method Put -Uri $url -ContentType 'application/json'