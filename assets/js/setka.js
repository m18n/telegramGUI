function Vp(){
    let sc=document.getElementById('sc');
    sc.scrollTop-=220;

}
function Nz(){
    let sc=document.getElementById('sc');
    sc.scrollTop+=220;
    
}
function CreateBlock(count){
   
    let my_div = document.getElementById("sc");
    for(let i=0;i<count;i++){
        var div=document.createElement("div");
        div.innerHTML = "<img src=\"img/load.png\" alt=\"\"><span id=\"load\">0%</span>";
        my_div.appendChild(div);
    }

}
function SetPath(idpath){
    var ts=idpath.split(":");
    let vdiv=document.getElementById("sc");
    let id=parseInt(ts[0]);
    vdiv.children[id].children[0].src=ts[1];
    
}