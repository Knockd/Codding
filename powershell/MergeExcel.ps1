$SourceExcelPath=Read-Host "Please input ExcelDirectoryPath"
Set-Location "$SourceExcelPath"
$SourceExcelFiles=GET-ChildItem $SourceExcelPath
# $OctMidDataExcel=Read-Host "Please input OctMidDataExcel"
$ObjectSourceExcel=NEW-OBJECT -ComObject Excel.application
# $ExcelWork.visible=$true
# $ExcelWork.workbooks.Add()
# $WorkSheet.Activate()
$ObjectDestExcel=NEW-OBJECT -ComObject Excel.application
$DestExcelPath=Read-Host "please input DestExcelPath"
$DestExcelPath
$DestWorkBook=$ObjectDestExcel.workbooks.open($DestExcelPath)
# $FinalPort.Activate()
$DestSheet=$DestWorkBook.Worksheets.item(1)
$DestRow=1
$DestStartRow=1
foreach ($file in $SourceExcelFiles)
{   
    $file.Name
    $SourceWorkBook=$ObjectSourceExcel.workbooks.open($SourceExcelPath+"\"+$file)
    $SourceSheet=$SourceWorkBook.WorkSheets.item(1)
    $rows=$SourceSheet.UsedRange.Rows.Count
    $cols=$SourceSheet.UsedRange.Columns.Count
    $rows
    # $cols
     $DestStartRow
    $ExcelData=[System.Collections.ArrayList]@()
    for($i=1;$i -lt $rows+1;$i++){
        for($j=1;$j -lt $cols+1;$j++){
            $temp=$SourceSheet.Cells.item($i,$j)
            # $temp.Text
            $null=$ExcelData.Add($temp.Text)

            # $DestSheet.cells.item($DestRow,$j)=$temp.Text
            # $DestWorkBook.save()
        }
        ++$DestRow
    }
    
    for($i=$DestStartRow;$i -lt $DestRow;$i++){
        for($j=1;$j -lt 7;$j++){
            $DestSheet.cells.item($i,$j)=$ExcelData[(($i-$DestStartRow)*6+$j-1)]
            $DestWorkBook.save()
        }
}
$DestStartRow+=$rows
$ExcelData=$null
}

$SourceWorkBook.close()
$DestWorkBook.close()
$ObjectSourceExcel.quit()
$ObjectDestExcel.quit()
