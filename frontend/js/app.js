import { Producto } from './domain/Producto.js';
import { AlmacenamientoMemoria } from './adapters/AlmacenamientoMemoria.js';

// --- INICIALIZACIÓN Y POBLACIÓN DE DATOS (Simulando el orquestador C++) ---
const db = new AlmacenamientoMemoria();
let productoSeleccionadoId = "001"; 

// Sincronizado estrictamente con orquestador_de_dependencias.cpp
db.guardarProducto(new Producto("001", "Agua Mineral Pureza", 10, 5, "Minalba", 1.50, "Botella - líquido", "6 cm x 6 cm x 20 cm", "AGUA / H2O", "V07AB", "Agua mineral de manantial pura extraida de la Cordillera de los Andes de Venezuela.", "Sede Chacao", "./assets/img/agua.png", "850 ml", "1 Botella"));
db.guardarProducto(new Producto("002", "Cafe Arabica Gourmet", 20, 8, "Fama de America", 12.50, "Bolsa - granos", "6 cm x 10 cm x 24 cm", "COFFEA ARABICA", "F10AA02", "Granos selectos de cafe Arabica 100% gourmet, tueste oscuro tradicional.", "Sede Las Mercedes", "./assets/img/cafe.jpg", "500 gramos", "1 Bolsa"));
db.guardarProducto(new Producto("003", "Azucar Refinada Premium", 12, 10, "Montalban", 2.20, "Saco - polvo", "5 cm x 15 cm x 28 cm", "SACAROSA", "A05AX01", "Azucar blanca refinada de cana de azucar con un estandar de pureza del 99.8%.", "Sede La Trinidad", "./assets/img/azucar.png", "1 Kilogramo", "1 Saco")); 
db.guardarProducto(new Producto("004", "Leche Organica Descremada", 15, 6, "Parmalat", 3.80, "Caja - líquido", "8 cm x 8 cm x 22 cm", "LACTOSA", "B02BB01", "Leche liquida descremada pasteurizada, enriquecida con vitaminas A y D.", "Sede Chacao", "./assets/img/leche.jpeg", "1 Litro", "1 Empaque"));
db.guardarProducto(new Producto("005", "Galletas de Avena Crujiente", 30, 15, "McVitie's", 4.50, "Caja - galletas", "4 cm x 8 cm x 18 cm", "AVENA SATIVA", "C03DA01", "Galletas de avena integral horneadas a fuego lento, ricas en fibra dietetica.", "Sede La Trinidad", "./assets/img/galletas.jpeg", "300 gramos", "12 Galletas"));

// --- SELECTORES DEL DOM ---
const selectProducto = document.getElementById('productoSelect');
const formVenta = document.getElementById('ventaForm');
const inputCantidad = document.getElementById('cantidadInput');
const tbodySimpleList = document.getElementById('inventarioSimpleList');
const badgeTotal = document.getElementById('totalProductosBadge');
const toastContainer = document.getElementById('toastContainer');
const htmlElement = document.documentElement;
const themeToggleBtn = document.getElementById('themeToggleBtn');
const sunIcon = document.getElementById('themeSunIcon');
const moonIcon = document.getElementById('themeMoonIcon');

// --- GESTIÓN DE MODO OSCURO ---
function setDarkMode(isDark) {
    if (isDark) {
        htmlElement.classList.add('dark');
        sunIcon.classList.remove('hidden');
        moonIcon.classList.add('hidden');
        localStorage.setItem('corestock-theme', 'dark');
    } else {
        htmlElement.classList.remove('dark');
        sunIcon.classList.add('hidden');
        moonIcon.classList.remove('hidden');
        localStorage.setItem('corestock-theme', 'light');
    }
}

const savedTheme = localStorage.getItem('corestock-theme');
const systemPrefersDark = window.matchMedia('(prefers-color-scheme: dark)').matches;
setDarkMode(savedTheme === 'dark' || (!savedTheme && systemPrefersDark));

themeToggleBtn.addEventListener('click', () => {
    setDarkMode(!htmlElement.classList.contains('dark'));
});

// --- RENDERIZADO DE INTERFAZ ---
function renderizarSelect() {
    selectProducto.innerHTML = '<option value="" disabled selected>Seleccione un item...</option>';
    db.obtenerTodos().forEach(prod => {
        const option = document.createElement('option');
        option.value = prod.id;
        option.disabled = prod.stockActual <= 0;
        option.textContent = `${prod.nombre.substring(0, 30)}... ${prod.stockActual <= 0 ? '(Agotado)' : `(Disp: ${prod.stockActual})`}`;
        selectProducto.appendChild(option);
    });
}

function renderizarTabla() {
    tbodySimpleList.innerHTML = '';
    const productos = db.obtenerTodos();
    badgeTotal.textContent = `${productos.length} Items`;

    productos.forEach(prod => {
        const div = document.createElement('div');
        const isSelected = prod.id === productoSeleccionadoId;
        div.className = `p-4 flex justify-between items-center cursor-pointer transition-all ${isSelected ? 'bg-blue-50/70 dark:bg-slate-800 border-l-4 border-l-brand-accent' : 'hover:bg-slate-50 dark:hover:bg-[#111c2e]'}`;
        
        div.onclick = () => {
            productoSeleccionadoId = prod.id;
            renderizarTabla();
            renderizarInspector();
        };

        const agotado = prod.stockActual === 0;
        const enAlerta = prod.stockActual < prod.stockMinimo;
        let stockBadge = agotado 
            ? `<span class="bg-red-100 dark:bg-red-950/40 text-red-700 dark:text-red-400 text-[10px] px-2 py-0.5 rounded font-extrabold uppercase">Agotado</span>`
            : enAlerta 
            ? `<span class="bg-amber-100 dark:bg-amber-950/40 text-amber-700 dark:text-amber-400 text-[10px] px-2 py-0.5 rounded font-extrabold uppercase">Reorden</span>`
            : `<span class="bg-emerald-100 dark:bg-emerald-950/40 text-emerald-700 dark:text-emerald-400 text-[10px] px-2 py-0.5 rounded font-extrabold uppercase">Estable</span>`;

        div.innerHTML = `
            <div class="space-y-1 pr-3">
                <p class="font-extrabold text-xs text-slate-800 dark:text-slate-100 line-clamp-1">${prod.nombre}</p>
                <div class="flex items-center gap-2 text-[10px] text-slate-400"><span>#${prod.id}</span><span>&bull;</span><span>${prod.marca}</span></div>
            </div>
            <div class="text-right flex flex-col items-end gap-1 shrink-0">
                <span class="text-xs font-black text-slate-800 dark:text-slate-200">${prod.stockActual} / ${prod.stockMinimo}</span>
                ${stockBadge}
            </div>
        `;
        tbodySimpleList.appendChild(div);
    });
}

function renderizarInspector() {
    const prod = db.buscarProductoPorId(productoSeleccionadoId);
    if (!prod) return;

    // Actualizamos la imagen usando un tag <img> real en lugar de emojis
    const imgContainer = document.getElementById('productImageContainer');
    imgContainer.innerHTML = `<img src="${prod.rutaImagen}" alt="${prod.nombre}" class="max-w-full h-auto object-contain rounded-lg" onerror="this.src='https://via.placeholder.com/150?text=No+Image';">`;

    document.getElementById('detailBrand').textContent = prod.marca;
    document.getElementById('detailName').textContent = prod.nombre;
    document.getElementById('detailPrice').textContent = `Bs. ${prod.precio.toLocaleString('es-VE', {minimumFractionDigits: 2})}`;
    document.getElementById('detailDescShort').textContent = `${prod.nombre} distribuido de forma oficial bajo control estricto en la región metropolitana de Caracas.`;

    document.getElementById('fieldMarca').textContent = prod.marca;
    document.getElementById('fieldModelo').textContent = prod.nombre.split(' ')[0] + " " + (prod.nombre.split(' ')[1] || "");
    document.getElementById('fieldType').textContent = "Alimento / Consumo";
    document.getElementById('fieldCantidad').textContent = prod.contenido;
    document.getElementById('fieldUnidades').textContent = prod.unidades;
    document.getElementById('fieldPresentacion').textContent = prod.presentacion;
    document.getElementById('fieldDimensiones').textContent = prod.dimensiones;
    document.getElementById('fieldSede').textContent = prod.sede;

    document.getElementById('valPrincipioActivo').textContent = prod.principioActivo;
    document.getElementById('valAtc').textContent = prod.atcCode;
    document.getElementById('valIndicacionesText').textContent = prod.indicaciones;

    const enAlerta = prod.stockActual < prod.stockMinimo;
    const seedStatus = document.getElementById('sedeSecurityState');
    if (prod.stockActual === 0) {
        seedStatus.innerHTML = `<span class="text-red-500 font-bold"><i class="fa-solid fa-circle-exclamation"></i> Sin existencias en Sede</span>`;
    } else if (enAlerta) {
        seedStatus.innerHTML = `<span class="text-amber-500 font-bold"><i class="fa-solid fa-triangle-exclamation"></i> Reorden Requerido</span>`;
    } else {
        seedStatus.innerHTML = `<span class="text-emerald-500 font-bold"><i class="fa-solid fa-circle-check"></i> Stock Conforme</span>`;
    }

    // Lógica de pines del mapa
    ['pinChacao', 'pinLasMercedes', 'pinLaTrinidad'].forEach(id => {
        document.getElementById(id).classList.remove('active-pin', 'z-20');
        document.getElementById(id).querySelector('i').className = "fa-solid fa-location-dot text-2xl text-slate-500 opacity-60";
    });

    const pinId = prod.sede.includes('Chacao') ? 'pinChacao' : prod.sede.includes('Mercedes') ? 'pinLasMercedes' : 'pinLaTrinidad';
    const targetPin = document.getElementById(pinId);
    if (targetPin) {
        targetPin.classList.add('active-pin', 'z-20');
        const colorClass = prod.stockActual === 0 ? 'text-red-500' : (enAlerta ? 'text-amber-500' : 'text-emerald-500');
        targetPin.querySelector('i').className = `fa-solid fa-location-dot text-2xl ${colorClass} drop-shadow-md`;
    }
}

// Global exposure for UI onclick handlers in HTML (since ES modules limit scope)
window.toggleAccordion = function(id) {
    const content = document.getElementById(id);
    const icon = document.getElementById(`icon-${id}`);
    content.classList.toggle('hidden');
    icon.classList.toggle('rotate-180');
};

function mostrarToast(mensaje, tipo = 'success') {
    const toast = document.createElement('div');
    const borderClass = tipo === 'success' ? 'border-l-emerald-500' : tipo === 'error' ? 'border-l-red-500' : 'border-l-amber-500';
    const iconClass = tipo === 'success' ? 'fa-circle-check text-emerald-500 animate-bounce' : tipo === 'error' ? 'fa-circle-xmark text-red-500' : 'fa-triangle-exclamation text-amber-500';

    toast.className = `toast-enter p-4.5 rounded-2xl shadow-xl border flex items-start gap-3.5 bg-white dark:bg-[#0f1826] border-slate-200 dark:border-slate-800 relative overflow-hidden w-full border-l-4 ${borderClass}`;
    toast.innerHTML = `
        <i class="fa-solid ${iconClass} text-xl mt-0.5"></i>
        <div class="flex-1"><p class="text-sm font-semibold text-slate-800 dark:text-slate-100 leading-relaxed">${mensaje}</p></div>
        <button onclick="this.parentElement.remove()" class="text-slate-400 hover:text-slate-600 dark:hover:text-slate-200 transition-colors focus:outline-none"><i class="fa-solid fa-xmark"></i></button>
    `;
    toastContainer.appendChild(toast);
    setTimeout(() => {
        if (toast.parentElement) {
            toast.classList.replace('toast-enter', 'toast-exit');
            setTimeout(() => toast.remove(), 400);
        }
    }, 5000);
}

formVenta.addEventListener('submit', (e) => {
    e.preventDefault();
    const idSeleccionado = selectProducto.value;
    const cantidad = parseInt(inputCantidad.value);

    if (!idSeleccionado) return mostrarToast("Por favor, seleccione un ítem.", "error");

    const producto = db.buscarProductoPorId(idSeleccionado);
    if (producto) {
        try {
            const requiereReabastecimiento = producto.reducirStock(cantidad);
            db.actualizarProducto(producto);
            mostrarToast(`Verificación Exitosa: Las ${cantidad} un. están disponibles en la ${producto.sede}.`, "success");
            
            if (requiereReabastecimiento) {
                setTimeout(() => mostrarToast(`<b>REORDEN REQUERIDO:</b> Stock por debajo del mínimo de seguridad.`, "warning"), 600);
            }
            formVenta.reset();
            renderizarSelect();
            renderizarTabla();
            renderizarInspector();
        } catch (error) {
            mostrarToast(error.message, "error");
        }
    }
});

document.addEventListener('DOMContentLoaded', () => {
    renderizarSelect();
    renderizarTabla();
    renderizarInspector();
});