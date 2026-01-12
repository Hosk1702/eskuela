class Video {
    constructor({
        name,
        last,
        url
    }){
        this.name = name;
        this.last = last;
        this.url = url;
    }
}

class Session {
    constructor({
        name,
        id,
        video,
        comments = []
    }){
        this.name = name;
        this.id = id;
        this.video = video;
        this.comments = comments;
    }

    AddComments(Newcomment){
        this.comments.push(Newcomment);
    }

    RemoveComment(Oldcomment){
        this.comments = this.comments.filter(comment => comment != Oldcomment)
    }
}

class Course {
    constructor({
        name,
        classes = [],
        isfree = false,
        lang = 'Spanish'

    }){
        this.name = name;
        this.classes = classes;
        this.isfree = isfree;
        this.lang = lang;
    }

    AddClasses(clas){
        this.classes.push(clas);
    }
}

const BasicPgm = new Course({
    name: 'Curso de Programacion basica',
    isfree: true,
    classes: [new Session ({
    name: 'Clase 1 de programacion basica',
    id: 1,
    video: new Video({
        name: 'Video 1 Programacion basica',
        last: 10.5,
        url : 'Mivideo.com'
    })
    })
    ]
})

const ExpertPgm = new Course({
    name: 'Curso de Programacion Avanzada',
    isfree: false,
    lang: 'English',
    classes: [new Session ({
    name: 'Clase 1 de programacion Avanzada',
    id: 1,
    video: new Video({
        name: 'Video 1 Programacion Avanzada',
        last: 10.5,
        url : 'Mivideo.com'
    })
    })
    ]
})

class Student {
    constructor({
        name,
        UserName,
        points = 0,
        Twitter = undefined,
        Instagram = undefined,
        Facebook = undefined,
        AprovedCourses = [],
        learningPaths = []
    }){
        this.name = name;
        this.UserName = UserName;
        this.points = points;
        this.SocialMedia = {
            Twitter: Twitter,
            Instagram: Instagram,
            Facebook: Facebook
        },
        this.AprovedCourses = AprovedCourses;
        this.learningPaths = learningPaths;
    }
        addAprovedCourses(course){
            this.AprovedCourses.push(course);
        }
}

class FreeStudent extends Student{
    constructor(props){
        super(props)
    }

    addAprovedCourses(course){
        if(course.isfree){
            this.AprovedCourses.push(course);            
        }
        else{
            console.error(`Lo sentimos el estudiante ${this.name} no puede aprobar cursos de paga`);
        }
    }
}

class BasicStudent extends Student{
    constructor(props){
        super(props)
    }

    addAprovedCourses(course){
        if(course.lang !== 'English'){
            this.AprovedCourses.push(course);            
        }
        else{
            console.error(`Lo sentimos el estudiante ${this.name} no puede aprobar cursos en ingles`);
        }
    }
}

class ExpertStudent extends Student{
    constructor(props){
        super(props)
    }

    addAprovedCourses(course){
        this.AprovedCourses.push(course);            
    }
}