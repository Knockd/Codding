$path="D:\江西移动\8月中间件\xlsx"
$workBooks=Get-ChildItem  -Path $path
$header=@("主机","域名","端口","协议","名称","简短描述")
$merge=New-Object System.Collections.ArrayList

foreach($wb in $workBooks){
    $fullpath=$wb.FullName
    $src=Import-Excel -Path $fullpath -HeaderName $header -StartRow 1
    foreach($obj in $src){
        [void]$merge.Add($obj)
    }
}
$merge | Export-Excel D:\test.xlsx
Write-Host Workbooks are fully merged!