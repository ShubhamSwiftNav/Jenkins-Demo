pipeline {
  agent any

    //Parametrize your Build
    ////// select version of the application you want to ddddddddddddeployyyyy .

  stages {

    stage("init") {
        steps {
        echo 'Pipeline INIT...'
    }}

    stage("build") { 
        steps {
        echo 'building the application...'
        sh 'rm -rf play'
        sh 'mkdir play && cd play && cp -r /home/Download/Jenkins/Project/Jenkins-Demo/ .'
        sh 'cd play && mkdir build && cd build && cmake ../.. && cmake --build .'
        sh ''
    }}
    stage("test") {
        steps {
          echo 'testing the application...'
          sh "play/build/tst/Factorial_test"
    }}
    stage('valid') {
        steps {
          echo 'send mail'
          emailext body:'test mail' ,recipientProviders: [[$class: 'DevelopersRecipientProvider'],[$class: 'RequestRecipientProvider']], subject:'Test'
    }}
    
    stage("deploy") {
        steps {
          echo 'deploying the application...'
        }
    }
  }
}
