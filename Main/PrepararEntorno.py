
import os
import platform
import subprocess
import time

# Función para ejecutar comandos del sistema
def ejecutar_comando(comando, descripcion):
    print(f"Iniciando: {descripcion}")
    resultado = subprocess.run(comando, shell=True)
    if resultado.returncode != 0:
        print(f"Error al ejecutar: {comando}")
    else:
        print(f"Completado: {descripcion}\n")

def detectar_sistema():
    """
    Detecta el sistema operativo y, si es Linux, identifica la distribución específica.
    Retorna el nombre del sistema operativo o la distribución.
    """
    import platform

    sistema = platform.system()

    if sistema == "Darwin":
        return "macOS"
    elif sistema == "Windows":
        return "Windows"
    elif sistema == "Linux":
        try:
            with open("/etc/os-release", "r") as f:
                info = f.read().lower()
            if "arch" in info:
                return "Arch"
            elif "debian" in info or "ubuntu" in info:
                return "Debian"
            elif "fedora" in info or "red hat" in info:
                return "Fedora"
            else:
                return "Linux"
        except FileNotFoundError:
            return "Linux"  
    else:
        return "Desconocido"
def instalar_paquete(paquete):
    distro = detectar_sistema()
    print(f"Detectando sistema operativo: {distro}")
    print(f"Instalando {paquete}...")

    if distro == "macOS":
        print("Para macOS, puedes usar Homebrew para instalar el paquete.")
        subprocess.run(["brew", "install", paquete])
    elif distro == "Windows":
        print("Para Windows, puedes usar Chocolatey o Winget para instalar el paquete.")
        subprocess.run(["winget", "install", paquete])
    elif distro == "Arch":
        print(f"Instalando {paquete} en Arch Linux con pacman.")
        subprocess.run(["sudo", "pacman", "-S", paquete])
    elif distro == "Debian":
        print(f"Instalando {paquete} en Debian/Ubuntu con apt.")
        subprocess.run(["sudo", "apt", "install", "-y", paquete])
    elif distro == "Fedora":
        print(f"Instalando {paquete} en Fedora con dnf.")
        subprocess.run(["sudo", "dnf", "install", "-y", paquete])
    else:
        print("Gestor de paquetes no soportado para esta distribución.")
        print(f"Intenta instalar {paquete} manualmente.")


# Función principal para compilar y ejecutar
def ejecutar_cpp():
    sistema = detectar_sistema()
    print(f"Detectando sistema operativo: {sistema}")
    
    # Ruta del archivo C++ principal
    archivo_cpp = "Main/ProyectoFund.cpp"
    ejecutable = "Creador_de_codigos_AEROPUERTOS"

    # Crear la carpeta build
    if not os.path.exists("build"):
        os.makedirs("build")

    try:
        # Comandos para compilar el programa usando CMake
        print("Compilando el proyecto...")
        ejecutar_comando("cd build && cmake .. && cmake --build .", "Compilación del proyecto con CMake")

        # Contador para mostrar progreso
        for i in range(3, 0, -1):
            print(f"Ejecutando el programa en {i} segundos...")
            time.sleep(1)

        # Ruta del ejecutable
        ruta_ejecutable = os.path.join("build", ejecutable)

        # Comprobar si el ejecutable existe y ejecutarlo
        if os.path.exists(ruta_ejecutable):
            print(f"Ejecutando el programa: {ruta_ejecutable}")
            ejecutar_comando(f"./{ruta_ejecutable}", "Iniciando el programa")
        else:
            print(f"No se encontró el ejecutable en {ruta_ejecutable}")
    except Exception as e:
        print(f"Error al ejecutar el programa: {e}")

# Llamada al programa
if __name__ == "__main__":
    print("Preparando el entorno para el proyecto...\n si eres de linux procura tener tu sistema actualizado!")
    instalar_paquete(str(input("Ingrese el nombre del paquete a instalar: ")))
    ejecutar_cpp()