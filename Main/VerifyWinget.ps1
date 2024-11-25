# Script para descargar e instalar Winget (Windows Package Manager)

# Verificar si Winget ya está instalado
if (Get-Command winget -ErrorAction SilentlyContinue) {
    Write-Host "Winget ya está instalado en el sistema."
} else {
    Write-Host "Winget no está instalado. Procediendo con la instalación..."

    # Descargar el instalador de App Installer desde GitHub (Winget se incluye aquí)
    $wingetURL = "https://github.com/microsoft/winget-cli/releases/latest/download/Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle"
    $installerPath = "$env:TEMP\Microsoft.DesktopAppInstaller.msixbundle"

    Write-Host "Descargando Winget desde $wingetURL..."
    Invoke-WebRequest -Uri $wingetURL -OutFile $installerPath -UseBasicParsing

    # Instalar el archivo descargado
    Write-Host "Instalando Winget..."
    Add-AppxPackage -Path $installerPath

    # Verificar si la instalación fue exitosa
    if (Get-Command winget -ErrorAction SilentlyContinue) {
        Write-Host "Winget se instaló correctamente."
    } else {
        Write-Host "Hubo un problema durante la instalación de Winget."
    }

    # Eliminar el instalador descargado
    Remove-Item $installerPath -Force
}

Write-Host "Proceso completado."
