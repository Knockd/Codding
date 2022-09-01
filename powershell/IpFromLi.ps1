set-Location "C:\Users\kali\desktop"
$array=@(get-content  ip.txt | ForEach-Object {$_.split()[1]} | ForEach-Object {$_.Trim()})
$xlFixedFormat = "Microsoft.Office.Interop.Excel.xlFixedFormatType" -as [type]
$objExcel = New-Object -ComObject excel.application
$objExcel.visible = $false
$path="C:\Users\kali\Downloads\maf_globalv4_addrfilter_config_export(10).csv"
$objExcel.workbooks.Add()
$workbook = $objExcel.workbooks.open($path)
$ws=$workbook.WorkSheets.item(1)
$workbook.activate()
$ws.activate()
$row=9
foreach($ip in $array){
    $row
    $ws.cells.item($row,1)=$ip
    $ws.cells.item($row,2)='2'
    $row=$row+1
} 
$workbook.save()
$workbook.close()
$objExcel.Quit()