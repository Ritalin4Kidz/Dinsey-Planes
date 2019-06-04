powershell -Command "(New-Object Net.WebClient).DownloadFile('%1', 'DinseyPlanes.zip')"
powershell -Command "Invoke-WebRequest %1 -OutFile DinseyPlanes.zip"
Extract