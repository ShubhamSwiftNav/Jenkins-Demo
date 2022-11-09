
pipeline {
  agent any

    //Parametrize your Build
    //// select version of the application you want to deploy .

  stages {

    stage("init") {
        steps {
        echo 'Pipeline INIT...'
    }}

    stage("build") { 
        steps {
        echo 'building the application...'
        sh 'rm -rf play'
        sh 'mkdir play && cd play && cp -r /home/jangoo/Desktop/demo/ .'
        sh 'cd play && mkdir build && cd build && cmake ../.. && cmake --build .'
        sh ''
    }}
    stage("test") {
        steps {
          echo 'testing the application...'
          sh "play/build/tst/Factorial_test"
    }}
    post {
        always {
          emailext body:'test mail' ,reciepientProviders: [[$class: 'sonalisajwan18@gmail.com'],[$class: 'sonalisajwan18@gmail.com']], subject:'Test'
         
    }}
    
    stage("deploy") {
        steps {
          echo 'deploying the application...'
        }
    }
  }
}
