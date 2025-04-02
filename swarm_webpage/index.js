let original = document.getElementById('march')
let right = document.getElementById('right')
let equi = document.getElementById('equi')


let handleEqui = ()=>{
    fetch(`http://192.168.4.1/formation?f=e`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
    fetch(`http://192.168.4.2/formation?f=e`).then((response)=>response.json()).then((res)=>console.log(res))
    fetch(`http://192.168.4.3/formation?f=e`).then((response)=>response.json()).then((res)=>console.log(res))
}

let handleOriginal = ()=>{
    fetch(`http://192.168.4.1/formation?f=l`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
    fetch(`http://192.168.4.2/formation?f=l`).then((response)=>response.json()).then((res)=>console.log(res))
    fetch(`http://192.168.4.3/formation?f=l`).then((response)=>response.json()).then((res)=>console.log(res))
}

let handleRight = ()=>{
    fetch(`http://192.168.4.1/formation?f=r`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
    fetch(`http://192.168.4.2/formation?f=r`).then((response)=>response.json()).then((res)=>console.log(res))
    fetch(`http://192.168.4.3/formation?f=r`).then((response)=>response.json()).then((res)=>console.log(res))
}

let dec1 = ()=>{
    fetch(`http://192.168.4.1/formation?f=d1`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let dec2 = ()=>{
    fetch(`http://192.168.4.1/formation?f=d2`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let dec3 = ()=>{
    fetch(`http://192.168.4.2/formation?f=d1`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let dec4 = ()=>{
    fetch(`http://192.168.4.2/formation?f=d2`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}
let dec5 = ()=>{
    fetch(`http://192.168.4.3/formation?f=d1`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let dec6 = ()=>{
    fetch(`http://192.168.4.3/formation?f=d2`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let inc1 = ()=>{
    fetch(`http://192.168.4.1/formation?f=i1`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let inc2 = ()=>{
    fetch(`http://192.168.4.1/formation?f=i2`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let inc3 = ()=>{
    fetch(`http://192.168.4.2/formation?f=i1`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let inc4 = ()=>{
    fetch(`http://192.168.4.2/formation?f=i2`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

let inc5 = ()=>{
    fetch(`http://192.168.4.3/formation?f=i1`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}
let inc6 = ()=>{
    fetch(`http://192.168.4.3/formation?f=i2`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
}

original.addEventListener("click",handleOriginal)
right.addEventListener("click",handleRight)
equi.addEventListener("click",handleEqui)

let i=1
let decs = [dec1,dec2,dec3,dec4,dec5,dec6]
let incs = [inc1,inc2,inc3,inc4,inc5,inc6]
while (i<7){
    document.getElementsByClassName("dec")[i-1].addEventListener("click", decs[i-1])
    document.getElementsByClassName("inc")[i-1].addEventListener("click", incs[i-1])
    i++;
}

// i=0;
// let j=0
// let x = document.getElementsByTagName("input")
// console.log(x.length)
// while(j<3){
//     document.getElementsByClassName("botForm")[j].addEventListener("click", (j)=>{
//         console.log(2*j,2*j+1)
//         let y1 = x[(2*j)].value
//         let y2 = x[(2*j)+1].value
//         console.log(y1,y2)
//         fetch(`http://192.168.4.${i+1}/speed?s1=${y1}&s2=${y2}`).then((response)=>response.json()).then((res)=>console.log(res)).catch((e)=>console.log(e))
//     })
//     j=j+1
// }
