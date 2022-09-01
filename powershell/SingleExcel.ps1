Stop-Process -Name "Excel"
$ObjectExcelSource=New-Object -ComObject Excel.application
$ObjectExcelDest=New-Object -ComObject Excel.application
$SourcePath=Read-Host "Please input sourceExcel"
$DestPath=Read-Host "Please input destExcel"
$WorkBookSource=$ObjectExcelSource.Workbooks.open($SourcePath)
$WorkBookDest=$ObjectExcelDest.Workbooks.open($DestPath)
$WorkSheetSource=$WorkBookSource.WorkSheets.item(1)
$WorkSheetDest=$WorkBookDest.WorkSheets.item(1)
$rows=$WorkSheetSource.UsedRange.Rows.Count()
$cols=$WorkSheetSource.UsedRange.Columns.Count()
$rows
$cols
$Row=1
# $temp=$WorkSheetSource.cells.item(1,1)
# $temp.Text
# $WorkSheetDest.cells.item($Row,$j)=$temp.Text
for($i=1; $i -lt $rows+1;$i++){

    for($j=1;$j -lt $cols+1;$j++){
        $temp=$WorkSheetSource.cells.item($i,$j)
        $temp.Text
        $WorkSheetDest.cells.item($Row,$j)=$temp.Text
        $WorkBookDest.save()
    }
    ++$Row
}
$WorkBookSource.save()
$WorkBookSource.close()
$ObjectExcelSource.quit()
$WorkBookDest.close()
$ObjectExcelDest.quit()
