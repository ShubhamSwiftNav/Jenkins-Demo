    //Parametrize your Build
    ////// select version of the application you want to deploy .
pipeline {
    agent any
    stages {
        
        stage('init') {
        steps {
        echo 'Pipeline INIT...'
    }}
        stage('build') { 
        steps {
        echo 'building the application...'
        sh 'rm -rf play'
        sh 'mkdir play && cd play && cp -r /home/jangoo/Downloads/Jenkins/Project/Jenkins-Demo/ .'
        sh 'cd play && mkdir build && cd build && cmake ../.. && cmake --build .'
        sh ''
    }}
    stage('test') {
        steps {
          echo 'testing the application...'
          sh "play/build/tst/Factorial_test"
    }}
        stage('Ok') {
            steps {
                echo "Ok"
            }
        }
    }
    post {
        always {
            emailext body: 'A Test EMail', recipientProviders: [[$class: 'DevelopersRecipientProvider'], [$class: 'RequesterRecipientProvider']], subject: 'Test'
        }
    }
}
