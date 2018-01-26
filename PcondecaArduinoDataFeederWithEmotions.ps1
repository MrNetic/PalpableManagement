#Data Feeder With Emotions
#Paulo Condeça 2018

#while var
$whileloop=0

# Adding serial port resouce
$port= new-Object System.IO.Ports.SerialPort COM7,9600,None,8,one

while ($whileloop -eq 0)
{

    # Looking for changes every minute
    Start-Sleep -s 1

    #Bellow is pseudo-sqlcmd that will return a value
    #This can be anything, in this case a query that return a value
    $Flag = Invoke-Sqlcmd -Query 
    "
    SELECT flag from mon.metric
    " 
    -ServerInstance ".\sqlvnext" -Database "YAPOC" ; 

    $processflag=$Flag.BlockedProcesses

    #Check if the flag is 0, that means everything is OK    
    $port.open()
    if ($processflag -eq 0)
    {
        $port.WriteLine(“t”)
    }
    else
    {
        $port.WriteLine(“f”)
    }
    #Close resource
    $port.close()
}

