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
        classes = []
    }){
        this.name = name;
        this.classes = classes;
    }

    AddClasses(clas){
        this.classes.push(clas);
    }
}

const BasicPgm = new Course({
    name: 'Curso de Programacion basica',
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

class LearningPath{
    constructor({
        name,
        courses = []   
    }
    ){
        this._name = name;
        this.courses = courses;
    }

    AddCourses(course){
        this.courses.push(course)
    }

    get name(){
        this._name;
    }

    set name(NewName){
        if (NewName === 'Pokemon es el peor juego del mundo'){
            console.error('Eso es imposible');
            return;
        }
        this._name = NewName;

    }
}

const WebDevelepmentSchool = new LearningPath({
    name: 'Fundamentos de desarrollo web',
    courses: [BasicPgm]
}
)
const VideogameDevelopmentSchool = new LearningPath({
    name: 'Fundamentos de desarrollo de videojuegos',
    courses: [BasicPgm]
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
        addAprovedCourses(){

        }

        addlearningpath(lp){
            this.learningPaths.push(lp);
        }   
}

const joan = new Student({
    name:'Juan',
    UserName: 'Juanito123',
    Twitter: 'Ingeperro123',
    learningPaths: [WebDevelepmentSchool]
})

console.log(WebDevelepmentSchool);
WebDevelepmentSchool.AddCourses(
    new Course({
        name: 'Curso de introduccion a html',
        classes: [new Session 
        ({
            name: 'Clase 1 Introduccion al diseño web',
            id: 1,
            video: new Video
                ({
                name: 'Video 1 Introduccion al diseño web',
                last: 10.5,
                url : 'Mivideo.com'
                })
        })
    ]})
)


console.dir(WebDevelepmentSchool, { depth: null });