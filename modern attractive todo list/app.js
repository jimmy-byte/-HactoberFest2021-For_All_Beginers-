const addForm = document.addFrm;
const text = addForm.add;
const ul = document.querySelector(".todos");

const addItem  = (item) =>{
    let list = `<li class="list-group-item d-flex justify-content-between align-items-center">
        <span> ${item} </span>
        <i class="far fa-trash-alt delete"></i>
        </li>`;
    ul.innerHTML += list;
}


addForm.addEventListener("submit", (e) => {
    e.preventDefault();
    let item = text.value;
    addItem(item);
    text.value = "";
});


ul.addEventListener("click", (e)=>{
    if(e.target.nodeName == 'I'){
        e.target.parentElement.remove();
    }
});


const searchItem = (text) =>{
    let listItem = ul.children;
    for(let x of listItem){
       if(x.innerText.toLowerCase().indexOf(text) == -1){
        x.classList.add("filtered");
       }else{
        x.classList.remove("filtered");
       }
    }
};

const search = document.querySelector(".search").search;
search.addEventListener("keyup", (e)=>{
    let text = search.value;
    searchItem(text.toLowerCase().trim());
});