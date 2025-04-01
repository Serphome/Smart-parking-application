# Smart Parking System - C++ Implementation

## Описание проекта

Это бэкенд-система для управления умной парковкой торгового центра, реализованная на C++. Проект включает функционал для:
- Учета въезда/выезда автомобилей
- Тарификации парковочных сессий
- Управления платежами
- Простой системы лояльности для зарегистрированных пользователей

## Основные функции

### Базовый функционал (5 баллов)
- `EnterParking()`: Регистрация въезда автомобиля
- `TryLeaveParkingWithTicket()`: Попытка выезда по билету
- `GetRemainingCost()`: Расчет стоимости парковки
- `PayForParking()`: Обработка платежа

### Дополнительные задачи:
1. **Сохранение данных (3 балла)**
   - Сериализация данных в файл
   - Загрузка данных при старте системы

2. **Система лояльности (2 балла)**
   - Регистрация пользователей
   - Привязка автомобилей к пользователям
   - Автоматическая обработка выезда по номеру автомобиля


## Особенности реализации

1. **Гибкая тарификация**:
   - Настраиваемые тарифные планы
   - Учет бесплатного периода после оплаты

2. **Обработка сценариев**:
   - Бесплатный короткий визит
   - Просроченный выезд
   - Доплата при задержке

3. **Оптимизации**:
   - Быстрый поиск по хеш-таблицам
   - Эффективное хранение данных

## Сборка и запуск

```bash
mkdir build && cd build
cmake ..
make
./smart_parking
