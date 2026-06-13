export class AlmacenamientoMemoria {
    constructor() {
        this.inventario = [];
    }
    
    guardarProducto(producto) {
        this.inventario.push(producto);
    }
    
    obtenerTodos() {
        return this.inventario;
    }
    
    buscarProductoPorId(id) {
        return this.inventario.find(p => p.id === id) || null;
    }
    
    actualizarProducto(productoActualizado) {
        const index = this.inventario.findIndex(p => p.id === productoActualizado.id);
        if (index !== -1) {
            this.inventario[index] = productoActualizado;
        }
    }
}