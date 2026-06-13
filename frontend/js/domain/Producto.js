export class Producto {
    constructor(id, nombre, stockInicial, stockMinimo, marca, precio, presentacion, dimensiones, principioActivo, atcCode, indicaciones, sede, rutaImagen, contenido, unidades) {
        this.id = id;
        this.nombre = nombre;
        this.stockActual = stockInicial;
        this.stockMinimo = stockMinimo;
        this.marca = marca;
        this.precio = precio;
        this.presentacion = presentacion;
        this.dimensiones = dimensiones;
        this.principioActivo = principioActivo;
        this.atcCode = atcCode;
        this.indicaciones = indicaciones;
        this.sede = sede; 
        this.rutaImagen = rutaImagen;
        this.contenido = contenido;
        this.unidades = unidades;
    }

    reducirStock(cantidad) {
        if (cantidad > this.stockActual) {
            throw new Error(`Existencias insuficientes. Solo hay ${this.stockActual} unidades disponibles.`);
        }
        if (cantidad <= 0) {
            throw new Error("La cantidad de despacho debe ser mayor a cero.");
        }
        this.stockActual -= cantidad;
        return this.stockActual < this.stockMinimo;
    }
}