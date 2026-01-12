function videoPlay(id){
    const url = 'https://PlatziClass.com/' + id;
    console.log('Se esta reproduciendo la url: ' + url);
}

function videoStop(id){
    const url = 'https://PlatziClass.com/' + id;
    console.log('Se pauso el video de la url: ' + url);
}

export class PlatziClass {
    constructor({
        name,
        videoiD
    }){
        this.name = name;
        this.videoiD = videoiD;
    }

    reproducir(){
        videoPlay(this.videoiD);
    }

    pausar(){
        videoStop(this.videoiD)
    }

}