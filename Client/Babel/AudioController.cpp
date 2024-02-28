#include "AudioController.h"

void CheckFiles(QString filePath, QUrl fileUrl)
{
    if (!fileUrl.isValid()) {
        qDebug() << "Erreur : Le chemin du fichier de sortie n'est pas valide.";
        throw std::exception();
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Erreur : Impossible d'écrire dans le répertoire de sortie.";
        throw std::exception();
    } else
        qDebug() << "valid";
    file.close();
}

AudioController::AudioController(QObject *parent)
    : QObject{parent}
{
    _session = std::make_shared<QMediaCaptureSession>();
    _input = std::make_shared<QAudioInput>();
    _recorder = std::make_shared<QMediaRecorder>();
    _output = std::make_shared<QAudioOutput>();
    _player = std::make_shared<QMediaPlayer>();
    _decoder = std::make_shared<QAudioDecoder>(this);
    _effect = std::make_shared<QSoundEffect>(this);
    _effect->setVolume(25);

    _recorder->setAudioSampleRate(16000);
    _recorder->setAudioBitRate(8);
    _recorder->setAudioChannelCount(2);
    _recorder->setMediaFormat(QMediaFormat::Wave);
    _recorder->setQuality(QMediaRecorder::NormalQuality);
    _recorder->setEncodingMode(QMediaRecorder::ConstantQualityEncoding);

    QAudioFormat desiredFormat;
    desiredFormat.setChannelCount(2);
    desiredFormat.setSampleFormat(QAudioFormat::Int16);
    desiredFormat.setSampleRate(16000);
    _decoder->setAudioFormat(desiredFormat);

    QString filePath = QDir(QCoreApplication::applicationDirPath()).filePath("test");
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    _recorder->setOutputLocation(fileUrl);
    CheckFiles(filePath, fileUrl);
    _fileUrl = fileUrl;
    qDebug() << "Chemin du fichier de sortie :" << filePath;
    qDebug() << "URI du fichier de sortie :" << fileUrl.toString();

    _session->setAudioInput(_input.get());
    _session->setRecorder(_recorder.get());
    connect(_recorder.get(), &QMediaRecorder::errorOccurred, this, &AudioController::handleError);
    connect(_decoder.get(), &QAudioDecoder::bufferReady, this, &AudioController::BufferRead);
}

void AudioController::SetInput()
{
}

void AudioController::RecordAudio()
{
    _recorder->record();
}

void AudioController::StopRecord()
{
    _recorder->stop();
}

bool AudioController::isRecording() const
{
    return _isRecording;
}

void AudioController::setIsRecording(bool newIsRecording)
{
    _isRecording = newIsRecording;
}

void AudioController::SetInputAudio(QByteArray id)
{
    foreach (auto devices, QMediaDevices::audioInputs()) {
        if (id == devices.id()) {
            _input->setDevice(devices);
            return;
        }
    }
    qDebug() << "Input not found!";
}

void AudioController::SetInputAudio(QAudioDevice device)
{
    _input->setDevice(device);
}

void AudioController::handleError(QMediaRecorder::Error error)
{
    qDebug() << "Recorder error:" << error;
}

void AudioController::ReadDecoder()
{
    emit(BufferRead());
}

std::vector<QByteArray> AudioController::buffers() const
{
    return _buffers;
}

void AudioController::AddBuffer(QByteArray arr)
{
    _buffers.push_back(arr);
}

void AudioController::DelFrontBuffer(QByteArray arr)
{
    _buffers.erase(_buffers.begin());
}

void AudioController::RefreshBuffer()
{
    // if (_player->playbackState() == QMediaPlayer::StoppedState) {
    if (_player->isAvailable()) {
        if (!_buffers.empty())
            _buffers.erase(_buffers.begin());
        QString targetPath = QDir(QCoreApplication::applicationDirPath()).filePath("target.wav");
        QFile target(targetPath);
        qint64 bytesWritten = 0;
        QByteArray str = _buffers.front();
        if (!target.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Append)) {
            qDebug() << "file couldn't be opened";
            throw std::exception();
        }
        bytesWritten = target.write(str);
        if (bytesWritten == -1) {
            qDebug() << "Erreur lors de l'écriture des données dans le fichier audio : " << target.errorString();
            return;
        }
        target.close();
        ListenAudio();
    }
}

void AudioController::ListenAudio()
{
    _player->setAudioOutput(_output.get());
    _output->setVolume(50);
    _player->setPosition(0);
    _player->setSource(QUrl::fromLocalFile("./target.wav"));
    _player->play();
}

void AudioController::setBuffers(const std::vector<QByteArray> &newBuffers)
{
    _buffers = newBuffers;
}

std::shared_ptr<QSoundEffect> AudioController::effect() const
{
    return _effect;
}

void AudioController::setEffect(const std::shared_ptr<QSoundEffect> &newEffect)
{
    _effect = newEffect;
}

std::shared_ptr<QMediaRecorder> AudioController::recorder() const
{
    return _recorder;
}

void AudioController::setRecorder(const std::shared_ptr<QMediaRecorder> &newRecorder)
{
    _recorder = newRecorder;
}

QByteArray AudioController::dataAudio() const
{
    return _dataAudio;
}

void AudioController::setDataAudio(const QByteArray &newDataAudio)
{
    _dataAudio = newDataAudio;
}

std::shared_ptr<QAudioDecoder> AudioController::decoder() const
{
    return _decoder;
}

void AudioController::setDecoder(const std::shared_ptr<QAudioDecoder> &newDecoder)
{
    _decoder = newDecoder;
}

char *AudioController::ReceivedData() const
{
    return _ReceivedData;
}

void AudioController::setReceivedData(char *newReceivedData)
{
    _ReceivedData = newReceivedData;
}

QAudioBuffer AudioController::SendData() const
{
    return _SendData;
}

void AudioController::setSendData(QAudioBuffer newSendData)
{
    _SendData = newSendData;
}

std::shared_ptr<QMediaPlayer> AudioController::player() const
{
    return _player;
}

void AudioController::setPlayer(const std::shared_ptr<QMediaPlayer> &newPlayer)
{
    _player = newPlayer;
}

QUrl AudioController::fileUrl() const
{
    return _fileUrl;
}

void AudioController::setFileUrl(const QUrl &newFileUrl)
{
    _fileUrl = newFileUrl;
}

std::shared_ptr<QAudioOutput> AudioController::output() const
{
    return _output;
}

void AudioController::setOutput(const std::shared_ptr<QAudioOutput> &newOutput)
{
    _output = newOutput;
}

void AudioController::setOutput(const QAudioDevice &output)
{
    _output->setDevice(output);
}
